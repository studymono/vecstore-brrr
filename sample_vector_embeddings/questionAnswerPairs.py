import json
import os
from openai import OpenAI
from dotenv import load_dotenv
from corpus import getQuestionAnswerPairs

load_dotenv()

client = OpenAI(
    organization=os.environ.get("OPENAI_ORGANIZATION"),
    project=os.environ.get("OPENAI_PROJECT"),
)

questionAnswerPairsWithEmbededings = getQuestionAnswerPairs()

for index, element in enumerate(questionAnswerPairsWithEmbededings):
    # generate embedding for the sentence
    response = client.embeddings.create(
        input=element["sentence"], model="text-embedding-3-small", dimensions=16
    )
    sentenceEmbedding = response.data[0].embedding

    # generate embedding for the question
    response = client.embeddings.create(
        input=element["question"], model="text-embedding-3-small", dimensions=16
    )
    questionEmbedding = response.data[0].embedding

    # update entry to include sentence and question embeddings
    questionAnswerPairsWithEmbededings[index]["sentenceEmbedding"] = sentenceEmbedding
    questionAnswerPairsWithEmbededings[index]["questionEmbedding"] = questionEmbedding

# dump these embeddings to a JSON file
with open("questionAnswerPairEmbeddings.json", "w") as file:
    json.dump(questionAnswerPairsWithEmbededings, file, indent=4)
