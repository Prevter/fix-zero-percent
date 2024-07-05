# Fix Zero Percentage

This mod fixes the bug when using Start Positions, that make the progress bar start from 0%.

Yep, that's it.


## How it works

Game uses ticks from attempt start to calculate level progress. It works just fine, but when you use Start Positions, tick timer starts from 0, which makes the progress bar start from 0% too.  
This mod makes it use the actual time since the level started, instead of ticks, which fixes the issue.