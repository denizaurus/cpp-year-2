#include < iostream >
#include < string >

void branch_for_conflict()
{
	//this is a function in branch_conflict for simulating conflict, TASK C
	return;
}

int main(int argc, char ** argv)
{
	system("pause");
	return EXIT_SUCCESS;
}

void main_for_rebasing()
{
	// this is a function in main for rebasing, TASK B
	return;
}

void branch_for_rebasing()
{
	// this is a function in branch_rebase for rebasing, TASK B 
	return;
}


/*
* MERGING VS REBASING
* 
* Merging is a direct connection to the previous commits, and results in a complicated
* yet definitive scheme of commits, their order and everything regarding the workflow.
* It can, however, get too complicated the more commits and branches there are, and
* that's where REBASE comes in.
* 
* Rebase finds the highest-ranking, or, upstream branch, tracks all the changes made
* in that branch, and finds its endpoint — one of the parents of the rebase-commit.
* Then, it calculates the differences between non-upstream commits, and applies them
* after the upstream endpoint one-by-one, until all changes are there and in order. 
* The previous commits are orphaned; thus rebase isn't advised to be used in repos
* others have fetch access to — fetch pulls in everything, including abandoned objects.
*/