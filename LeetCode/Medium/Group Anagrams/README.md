49. Group AnagramsSolvedMediumTopicsCompaniesGiven an array of strings strs, group the anagrams together. You can return the answer in any order.

 
Example 1:


Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:


	There is no string in strs that can be rearranged to form "bat".
	The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
	The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.



Example 2:


Input: strs = [""]

Output: [[""]]


Example 3:


Input: strs = ["a"]

Output: [["a"]]


 
Constraints:


	1 <= strs.length <= 104
	0 <= strs[i].length <= 100
	strs[i] consists of lowercase English letters.

 Seen this question in a real interview before?1/5YesNoAccepted4,045,741/5.7MAcceptance Rate71.3%TopicsArrayHash TableStringSortingCompaniesSimilar QuestionsValid AnagramEasyGroup Shifted StringsMediumFind Resultant Array After Removing AnagramsEasyCount AnagramsHardDiscussion (336)Choose a typeComment💡 Discussion Rules1. Please don't post any solutions in this discussion.2. The problem discussion is for asking questions about the problem or for sharing tips - anything except for solutions.3. If you'd like to share your solution for feedback and ideas, please head to the solutions tab and post it there.Sort by:BestHandsomeJensJan 24, 2024Just wanna give props to myself. This was my first medium :) Read more53814NikitaMar 23, 2023 An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Input:
strs = ["",""]
Expected:
[["",""]]
Where are the letters or words? Read moreAsk Question1968DIVITE DINESHFeb 06, 2024Finally can solve this after revisiting 5 times in 6 months.
This journey is going incredibly well. 🚀 Read more1461Sawan KushwahOct 01, 2023Approach
take out string
char array
sort it
convert to string
use this string as a key
then push all the related element to key Read more17921Freeze FrancisAug 10, 2021This question was part of interview rounds of Amazon.
For folks preparing for FAANG interview please read my interview experience.
https://freezefrancis.medium.com/amazon-sde-interview-experience-on-campus-e8444ee791b Read more1403An-Wen DengFeb 06, 2024Hash table must be used, because this is a strings' question.
One tip:  strings are anagrams <=> same string after sorting. No need for frequency count unless the string is super long.
Have a nice day! Read more403Bohdan PozharskyiNov 02, 2013What does it mean "return all groups"? But the return result is vector? How can we return all groups? I mean, for example, we have such vector ["dog","cat","god","tac"]. What should I return? Read more1134MrLebovskySep 01, 2023It says: " You can return the answer in any order", but console result is:
Output
[["ddddddddddg","dgggggggggg"]]
Expected
[["dgggggggggg"],["ddddddddddg"]]
Why? Read more468Mahdy KhayyamianFeb 01, 2015Why the output is list and not a list of list. What If there are multiple groups of anagrams? Read more393SamMy89Nov 04, 2014I found nice solution in Java in the internet, and it worked. However, I really don't understand the question. It says

return all groups of strings that are anagrams.

i.e. if we have two groups of strings that are anagrams we have to return two goups of strings, i.e. we need List<List<String>>. But in the problem description the method signature is given by List<String>. Does it mean that we always assume that we have only one group of string every time? Can someone please clarify this for me? Read more176123434Copyright © 2025 LeetCode. All rights reserved.