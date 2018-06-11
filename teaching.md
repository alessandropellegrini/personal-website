---
layout: default
title: Teaching
permalink: /teaching/
---

Office Hours
------------

Students office consulting is on the 1<sup>st</sup> and on the 3<sup>rd</sup> Wednesday of every month, from 3.00 pm to 4.30 pm, at Via Ariosto 25, room B120.

**Update**: Office hours on Wednesday May, 2 are moved to Monday 7, at 3.00 pm.

[//]: # (Office hours are suspended until the end of April.)

[//]: # (Students are received **upon appointment only**.    )
[//]: # (Please contact me via email to request an appointment.)


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
