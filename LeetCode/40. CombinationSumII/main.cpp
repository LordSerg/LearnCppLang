#include <iostream>
#include <vector>
#include <algorithm>
/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/

void f(std::vector<int> candidates, int target, int sum, std::vector<int> comb, std::vector<std::vector<int>>& answer, int toRemove)
{
	comb.push_back(toRemove);
	auto it = std::find(candidates.begin(), candidates.end(), toRemove);
		candidates.erase(it);
	if(sum==target)
	{
		std::sort(comb.begin(),comb.end());
		if(std::count(answer.begin(), answer.end(), comb) == 0)
			answer.push_back(comb);
		return;
	}
	if(sum > target || candidates.size() == 0)
	{
		return;
	}
	for(int i=0;i<candidates.size();++i)
	{
		auto it = std::find(candidates.begin(), candidates.end(), candidates[i]);
		if (it != candidates.end())
			f(candidates, target, sum+candidates[i], comb, answer, candidates[i]);
	}
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) 
{
	
	std::vector<std::vector<int>> answer{};
	int s=0;
	for(auto a : candidates)
		s+=a;
	if(s<target)
		return answer;
	std::vector<int> tmp{};
	for(int i=0;i<candidates.size();++i)
	{
		auto it = std::find(candidates.begin(), candidates.end(), candidates[i]);
		if (it != candidates.end())
			f(candidates, target, candidates[i], tmp, answer, candidates[i]);
	}
	return answer;
}

int main()
{
	std::vector<int> c{23,32,22,19,29,15,11,26,28,20,34,5,34,7,28,33,30,30,16,33,8,15,28,26,17,10,25,12,6,17,30,16,6,10,23,22,20,29,14,5,6,5,5,6,29,20,34,24,16,7,22,11,17,7,33,21,13,15,29,6,19,16,10,21,21,28,8,6};
	int target = 27;
	std::vector<std::vector<int>> answer = combinationSum2(c, target);
	std::cout<<"answer:\n";
	for(auto a : answer)
	{
		std::cout<<"[";
		for(auto b : a)
		{
			std::cout << b <<" ";
		}
		std::cout<<"]\n";
	}
}

