```mermaid
graph TB
    subgraph "Source Systems"
        S1[MongoDB]
        S2[PostgreSQL]
        S3[MySQL]
        S4[Oracle]
    end
    
    subgraph "Data Integration Platform"
        subgraph "Source Connector Layer"
            SC[Source Connectors]
            CDC[CDC Engine]
            BE[Batch Extractor]
            SD[Schema Discovery]
        end
        
        subgraph "Staging Area"
            DL[Data Lake<br/>S3/Azure Blob]
            MQ[Message Queue<br/>Apache Kafka]
            TD[Temp Database]
            DC[Data Catalog]
        end
        
        subgraph "Transformation Layer"
            SME[Schema Mapping<br/>Engine]
            DTC[Data Type<br/>Converter]
            BRE[Business Rules<br/>Engine]
            DQS[Data Quality<br/>Service]
            ES[Enrichment<br/>Service]
        end
        
        subgraph "Metadata Store"
            MS[(Metadata<br/>Database)]
            SI[Search Index<br/>Elasticsearch]
            CL[Cache Layer<br/>Redis]
        end
        
        subgraph "Orchestration Layer"
            WE[Workflow Engine<br/>Apache Airflow]
            JS[Job Scheduler]
            DM[Dependency<br/>Manager]
            RM[Resource<br/>Manager]
        end
        
        subgraph "Monitoring & Alerting"
            MC[Metrics Collection<br/>Prometheus]
            LA[Log Aggregation<br/>ELK Stack]
            DT[Distributed Tracing<br/>Jaeger]
            AE[Alerting Engine]
            DS[Dashboard Service<br/>Grafana]
        end
    end
    
    subgraph "Target Systems"
        T1[PostgreSQL]
        T2[Snowflake]
        T3[BigQuery]
        T4[Redshift]
    end
    
    subgraph "External Services"
        SSO[SSO/Auth Provider]
        SM[Secret Manager]
        NT[Notification Service]
        CS[Cloud Storage]
    end
    
    %% Data Flow Connections
    S1 --> SC
    S2 --> SC
    S3 --> SC
    S4 --> SC
    
    SC --> CDC
    SC --> BE
    SC --> SD
    
    CDC --> MQ
    BE --> DL
    SD --> DC
    
    MQ --> SME
    DL --> SME
    DC --> MS
    
    SME --> DTC
    DTC --> BRE
    BRE --> DQS
    DQS --> ES
    
    ES --> T1
    ES --> T2
    ES --> T3
    ES --> T4
    
    %% Control Flow Connections
    WE --> SC
    WE --> SME
    JS --> WE
    DM --> WE
    RM --> WE
    
    %% Metadata Flow
    MS --> SME
    MS --> SC
    MS --> WE
    SI --> MS
    CL --> MS
    
    %% Monitoring Flow
    SC --> MC
    SME --> MC
    WE --> MC
    MC --> LA
    MC --> DT
    MC --> AE
    AE --> DS
    
    %% External Integrations
    SSO --> SC
    SM --> SC
    NT --> AE
    CS --> DL
    
    %% Styling
    classDef sourceNode fill:#e1f5fe
    classDef platformNode fill:#f3e5f5
    classDef targetNode fill:#e8f5e8
    classDef externalNode fill:#fff3e0
    
    class S1,S2,S3,S4 sourceNode
    class SC,CDC,BE,SD,DL,MQ,TD,DC,SME,DTC,BRE,DQS,ES,MS,SI,CL,WE,JS,DM,RM,MC,LA,DT,AE,DS platformNode
    class T1,T2,T3,T4 targetNode
    class SSO,SM,NT,CS externalNode
