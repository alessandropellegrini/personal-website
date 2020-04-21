---
layout: default
title: Teaching
permalink: /teaching/
---

Office Hours
------------

<span style="color: red; font-weight: bold;">Based on the provisions of the competent authorities (Decree of the President of the Council of Ministers of 4 March 2020), face to face office hours are suspended until 3 April 2020 in relation to the Coronavirus emergency.</span>

<span style="color: red; font-weight: bold;"><u>Remote office hours will replace regular ones</u>. To allow a seamless experience, please send an email to the teacher booking for a specific date below, and specify a Skype account or a Google account. You will be provided with a 15-minutes time slot, and you will be contacted by the teacher at that time, either on Skype or on Google Meet. In case of a no show, you will lose your slot.</span>

Students office consulting is at:

* ~~Sapienza [S]: at Via Ariosto 25, room B120~~
* ~~Tor Vergata [T]: at Viale del Politecnico, room A1-05~~

according to the following schedule:

* Monday March 16 2020, 11.00 - 12.30 (see note above)
* Tuesday March 24 2020, 11.00 - 12.30 (see note above)
* Monday March 30 2020, 11.00 - 12.30 (see note above)

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