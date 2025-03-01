import requests 
import json 

response = requests.post(
    url='http://openrouter.ai/api/v1/chat/completions',
    headers={
        "Authorization":"Bearer sk-or-v1-725d2dff49ffa3ebf8f7aa952c74daffd1531a1b9f6d5ae532612c493a7206",
        "content-type":"application/json"
    },
    data=json.dumps({
        "model":"nousresearch/deephermes-3-llama-3-8b-preview:free",
        "messages":[{
            "user":"Hello, how are you?"
        }]
    })
)

print(response.json())
