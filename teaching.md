---
layout: default
title: Teaching
permalink: /teaching/
---

Office Hours
------------

Students office consulting is at:

* Sapienza [S]: at Via Ariosto 25, room B120
* Tor Vergata [T]: at Viale del Politecnico, room A1-05

according to the following schedule:

* [T] Monday February 17 2020, 11.00 - 12.30
* [S] Thursday February 27 2020, 11.00 - 12.30

Please note that if no student shows up at the beginning of the office hours, I might leave the office to carry out other tasks.

<span style="color: red; font-weight: bold;">
</span>


Courses
-------

{% for post in site.posts  %}

{% capture this-year %}{{ post.date | date: "%Y" }}{% endcapture %}
{% capture next-year %}{{ post.previous.date | date: "%Y" }}{% endcapture %}

{% if forloop.first %}
{{ this-year }}/{{ this-year | plus: 1 }}
---------------
{% endif %}

* [{{ post.title }}]({{ site.url }}/{{ post.url }})

{% if forloop.last %}
{% else %}
{% if this-year != next-year %}
{{ next-year }}/{{ next-year | plus: 1 }}
---------------
{% endif %}
{% endif %}
{% endfor %}
