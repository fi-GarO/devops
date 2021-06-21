import requests
from requests.structures import CaseInsensitiveDict

url = "https://api.eu.opsgenie.com/v1/json/freshdesk?apiKey=ae047cd1-485c-4932-9906-64e851b552a4" #Nový comment
#"https://api.eu.opsgenie.com/v1/json/freshdesk?apiKey=a650e10f-76d6-4c52-9bff-8a506e64cf9e" #Nový ticket


data = """
{
    "freshdesk_webhook": {
        "ticket_id": 2,
        "ticket_subject": "test subject",
        "ticket_description": "test deskripsiyon",
        "ticket_url": "https://opsgenie.freshdesk.com/helpdesk/tickets/2",
        "ticket_portal_url": "https://opsgenie.freshdesk.com/support/tickets/2",
        "ticket_due_by_time": "March 23 2016 at 10:06 AM",
        "ticket_tags": "tag1, tag2",
        "ticket_latest_public_comment": "pablik",
        "ticket_latest_private_comment": null,
        "ticket_group_name": "Product Management",
        "ticket_agent_name": "eycint",
        "ticket_agent_email": "agent1@asd.com",
        "ticket_satisfaction_survey": "test data",
        "ticket_status": "Open",
        "ticket_priority": "Medium",
        "ticket_source": "Phone",
        "ticket_type": "Incident",
        "requester_name": "halit okumus",
        "ticket_requester_firstname": "halit",
        "ticket_requester_lastname": "okumus",
        "ticket_requester_email": "halit@opsgenie.com",
        "ticket_requester_phone": "1222",
        "ticket_requester_address": "adres",
        "ticket_company_name": "OpsGenie",
        "ticket_company_description": "compa desc",
        "ticket_company_note": "compnot",
        "ticket_company_domains": null,
        "helpdesk_name": "opsgenie",
        "ticket_portal_name": "opsgenie",
        "ticket_product_description": "",
        "triggered_event": "{ticket_action:created}"
    }
}
"""


resp = requests.post(url, data=data)

print(resp.status_code)