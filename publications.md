---
layout: default
title: Research & Publications
permalink: /publications/
inproceedings: 0
---


{% comment %} Store the count of publication groups {% endcomment %}
{% capture book_count %}{% bibliography_count -q @book[author ~= Pellegrini] %}{% endcapture %}
{% capture incollection_count %}{% bibliography_count -q @incollection[author ~= Pellegrini] %}{% endcapture %}
{% capture article_count %}{% bibliography_count -q @article[author ~= Pellegrini] %}{% endcapture %}
{% capture inproceedings_count %}{% bibliography_count -q @inproceedings[author ~= Pellegrini] %}{% endcapture %}
{% capture other_count %}{% bibliography_count -q @techreport[author ~= Pellegrini] @unpublished[author ~= Pellegrini] %}{% endcapture %}


Research Interests
------------------

My research is mainly focused on:

* Parallel and Distributed Discrete Event Simulation;
* Optimistic Synchronization;
* Autonomic Computing;
* Code Parallelization Techniques;
* Post-Mortem Debugging;
* Code Instrumentation Techniques;
* Modelling and Performance Evaluation of Simulation Systems;
* Computer Architectures;
* Operating Systems.

Publication Archive
-------------------
(You can also access my personal pages at
[DBLP](http://dblp.uni-trier.de/pers/hd/p/Pellegrini_0001:Alessandro),
[ACM](http://dl.acm.org/author_page.cfm?id=81440592391), and
[Google Scholar](http://scholar.google.it/citations?user=lrxSz_0AAAAJ)).


**Copyright Information**: The documents available from this site are provided as a means to ensure timely dissemination of technical work on a non-commercial basis. Copyright and all rights therein are maintained by the authors or by other copyright holders, notwithstanding that they have offered their works here electronically. It is understood that all persons copying this information will adhere to the terms and constraints invoked by each author's copyright. These works may not be reposted without the explicit permission of the copyright holder. Permission to make digital or hard copies of part or all of these works for personal or classroom use is granted without fee provided that copies are not made or distributed for profit or commercial advantage. The electronic version of some of the works available from this site may differ from the definitive published version. Copyright of works submitted for publication may be transferred without further notice and this version may no longer be accessible.


**Apply Filters**:
<label><input type="checkbox" onClick="toggle('book')" checked/> <img src="{{ site.url }}/images/book-box.png"/> Books ({{ book_count }})</label>
<label><input type="checkbox" onClick="toggle('incollection')" checked/> <img src="{{ site.url }}/images/incollection-box.png"/> Book Chapters ({{ incollection_count }})</label>
<label><input type="checkbox" onClick="toggle('article')" checked/> <img src="{{ site.url }}/images/article-box.png"/> Journal Articles ({{ article_count }})</label>
<label><input type="checkbox" onClick="toggle('inproceedings')" checked/> <img src="{{ site.url }}/images/inproceedings-box.png"/> Conference Proceedings ({{ inproceedings_count }})</label>
<label><input type="checkbox" onClick="toggle('other')" checked/> <img src="{{ site.url }}/images/informal-box.png"/> Other publications ({{ other_count }})</label>      
(total publications: {% bibliography_count -q @*[author ~= Pellegrini] %})

{% bibliography -q @*[author ~= Pellegrini] %}
