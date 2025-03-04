#!/bin/bash
set -e

# Get current date in YYYYMMDD format
DATE_TAG=$(date +%Y%m%d)

# Build Docker image
echo "Building Docker image..."
docker build -t tindy2013/subconverter:latest -t tindy2013/subconverter:$DATE_TAG -f scripts/Dockerfile .

# Push images
echo "Pushing Docker images..."
docker push tindy2013/subconverter:latest
docker push tindy2013/subconverter:$DATE_TAG

echo "Successfully built and pushed Docker images with tags: latest and $DATE_TAG" 