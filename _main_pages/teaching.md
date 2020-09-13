---
layout: default
title: Teaching
permalink: /teaching/
---

Office Hours
------------

Students office consulting is at:

* Tor Vergata (Viale del Politecnico 1), Ingegneria dell'Informazione Building, Room A1-05
* Online (Google Meet)

Due to the Coronavirus pandemic, online consulting shall be preferred. In order to book an appointment, please send me an email.

Please note that if no student shows up at the beginning of the office hours, I might leave the office to carry out other tasks.


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