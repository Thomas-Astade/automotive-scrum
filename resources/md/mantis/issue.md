The "issue" in Mantis
---------------------

The issue in Mantis can have 7 states:

* __New__
  Is the state after the issue is entered. There must be a review of issues in the state "new".
* __Feedback__
  Issues in the state "Feedback" are send back to the issuer (or tester). This indicates, that there are some informations missing
  or some additional informations are needed.
* __Acknowledged__
  Issues in "Acknowledged" state have passed the review. It means, that they are formally correct and contain all needed information.
* __Confirmed__
  Issues in "Confirmed" are in a state that indicates, that they will be done.
* __Assigned__
  Issues in "Assigned" have already a role assigned, that is intendet to work on it.
* __Resolved__
  In this state the issue is ready for testing by a tester or the issuer.
* __Closed__
  There will not be any further activity on that issue. This is ether because it was successfully handled, or because it was never 
  confirmed.

Some guidelines for entering issues
-----------------------------------

If you enter an issue you want help. Mostly you want it fast. So it seems that there is no time to enter all the information fields which are requested.

Often this ends up, that feedback is needed. So if you enter an issue, take you time. Enter all information you have, especially release information, because this is not obvious. Use exact release numbers not pfrases like "new release" or "latest software".

Please describe, what you expected to happen! This is obvious for __you__ but not for the reader of the issue. In addition, explain how someone else (who might not have your environment) can reproduce the behavior. Yes, that's maybe not easy!

And last but not least, describe the wrong behaviour you saw. Attach traces, dumps, screenshots, test data ... whatever might be useful to understand what was going wrong.


