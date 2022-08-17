
# Get info pro komponentu
curl -i -X GET \
  -H 'Authorization:OAuth **doplň-si-sem-APIkey-ze-SP**' \
  'https://api.statuspage.io/v1/pages/lp9fc6wp9l69/components/rq64j6m8t0ft/uptime'

+ page id - lp9fc6wp9l69
+ components id - rq64j6m8t0ft

Doplň si do Curlu API klíč (normálně na SP v API info), Github mám public tak jsem ho pro jistotu nechtěl nahrávat
+ Výstup z Curlu redirectnout do spData.json (natvrdo napsaný)
+ Potřeba smazat balast, aby z toho výstupu byl čistej JSON

# Update maintenance 
- API: https://developer.statuspage.io/#operation/putPagesPageIdIncidentsIncidentId
- page_id: lp9fc6wp9l69
- incident_id: gkf188bkm6b7
- token: 5b1f0039-a0b1-4013-baf1-9e1fd17f3324

curl https://api.statuspage.io/v1/pages/lp9fc6wp9l69/incidents/gkf188bkm6b7 \
  -H "Authorization: 5b1f0039-a0b1-4013-baf1-9e1fd17f3324" \
  -X PATCH \
  -d "incident[body]=Dobrý den, %0Adovolujeme si Vás informovat o plánovaném nasazení backendu pro WAVIN/SENTIO, které po dohodě s JABLOTRON CONTROLS proběhne ve čtvrtek 18. 8. 2022 od 13:00 do 13:30.%0APo dobu této maintenance může dojít ke zpomalení dat v aplikaci WAVIN/SENTIO, včetně ovládání.%0A%0ADěkujeme za spolupráci a pochopení,%0AJCS SUPPORT tým"
# Get info for incident
  curl https://api.statuspage.io/v1/pages/lp9fc6wp9l69/incidents/trcjcpb4djh7 \
  -H "Authorization: 5b1f0039-a0b1-4013-baf1-9e1fd17f3324" \
  -X GET