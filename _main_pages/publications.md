---
layout: default
title: Research & Publications
permalink: /publications/
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


**Copyright Information**:
The documents available from this site are provided as a means to ensure the timely dissemination of technical work on a non-commercial basis. Copyright and all rights therein are maintained by the authors or other copyright holders, notwithstanding that they have offered their works here electronically. It is understood that all persons copying this information will adhere to the terms and constraints invoked by each author’s copyright. These works may not be reposted without the copyright holder's explicit permission. Permission to make digital or hard copies of part or all of these works for personal or classroom use is granted without fee, provided that copies are not made or distributed for profit or commercial advantage. The electronic version of some of the works available on this site may differ from the definitive published version. Copyright of works submitted for publication may be transferred without further notice, and this version may no longer be accessible.

**Apply Filters**

<label class="checkboxes"><input type="checkbox" onClick="toggle('book')" checked/><span><img alt="book" src="{{ site.url }}/images/book-box.png"/> Books ({{ book_count }})</span></label>
<label class="checkboxes"><input type="checkbox" onClick="toggle('incollection')" checked/><span><img alt="chapter" src="{{ site.url }}/images/incollection-box.png"/> Book Chapters ({{ incollection_count }})</span></label>
<label class="checkboxes"><input type="checkbox" onClick="toggle('article')" checked/><span><img alt="article" src="{{ site.url }}/images/article-box.png"/> Journal Articles ({{ article_count }})</span></label>
<label class="checkboxes"><input type="checkbox" onClick="toggle('inproceedings')" checked/><span><img alt="conference" src="{{ site.url }}/images/inproceedings-box.png"/> Conference Proceedings ({{ inproceedings_count }})</span></label>
<label class="checkboxes"><input type="checkbox" onClick="toggle('other')" checked/><span><img alt="other" src="{{ site.url }}/images/informal-box.png"/> Other publications ({{ other_count }})</span></label>
(total publications: {% bibliography_count -q @*[author ~= Pellegrini] %})

<div id="columnchart_material" style="width: 400px; height:200px"></div>

{% bibliography -q @*[author ~= Pellegrini] %}



<script type="text/javascript">
      google.charts.load('current', {'packages':['bar']});
      google.charts.setOnLoadCallback(drawChart);

      function drawChart() {
        var data = google.visualization.arrayToDataTable([
          ['', 'Books', 'Chapters', 'Articles', 'Proceedings', 'Other'],
{%- assign currYear = 'now' | date: "%Y" -%}
{%- for i in (2009..currYear) -%}
['{{ i }}', {% bibliography_count -q @book[author ~= Pellegrini, year={{i}}] %}, {% bibliography_count -q @incollection[author ~= Pellegrini, year={{i}}] %}, {% bibliography_count -q @article[author ~= Pellegrini, year={{i}}] %}, {% bibliography_count -q @inproceedings[author ~= Pellegrini, year={{i}}] %}, {% bibliography_count -q @techreport[author ~= Pellegrini, year={{i}}] %}],
{%- endfor -%}
        ]);


	var options = {
             isStacked: true,
             height: 200,
             width: 400,
             legend: {position: 'none'},
             vAxis: {minValue: 0},
             series: {
		    0:{color:'#f8c91f'},
		    1:{color:'#ef942d'},
		    2:{color:'#c32b72'},
		    3:{color:'#196ca3'},
		    4:{color:'#606b70'}
		  }
        };

        var chart = new google.charts.Bar(document.getElementById('columnchart_material'));

        chart.draw(data, google.charts.Bar.convertOptions(options));
      }
    </script>
