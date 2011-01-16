<div id="date">
{% if page.date %}
   {{ page.date | date: "%a %d %b %Y" }}
{% endif %}
{% if my_date %}
   {{ my_date }}
{% endif %}
</div>
