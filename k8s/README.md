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

# describe pod 
kubectl describe pod <pod-name>

# get namespaces 
kubectl config use-context argocd

# get context where its running
kubectl config get-contexts

# check deployments for specific namespace
kubectl get deployments -n argocd

# working argo 
kubectl apply -n argocd -f https://raw.githubusercontent.com/argoproj/argo-cd/stable/manifests/install.yaml 

# get node - whole K8s cluster
kubectl get nodes

# drain node
kubectl drain <node-name> --ignore-daemonsets
kubectl drain desktop-nb5kn69 --ignore-daemonsets --delete-emptydir-data

# uncordon node

kubectl uncordon <node-name>

# argo get admin password
kubectl -n argocd get secret argocd-initial-admin-secret -o jsonpath="{.data.password}" | base64 -d

# logs

kubectl -n argocd logs argocd-server-5985b6cf6f-s8hkd


# helm

curl -fsSL -o get_helm.sh https://raw.githubusercontent.com/helm/helm/master/scripts/get-helm-3

# use helm to install argo with -f values.yaml
helm install argocd argo/argo-cd -n argocd --create-namespace -f values.yaml

# port forward
kubectl port-forward service/argocd-server -n argocd 8080:443