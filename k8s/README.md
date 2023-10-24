# Create basic grafana deployment
kubectl apply -f grafana-deployment.yml

# Create grafana service
kubectl apply -f grafana-service.yml

# Access Grafana 
localhost:31156 
    - Port dostaneš přes:
    kubectl get svc grafana

# scale down
kubectl scale deployment <deployment-name> --replicas=0

# delete deploy
kubectl delete deployment <deployment-name>

# delete service
kubectl delete service <service-name>