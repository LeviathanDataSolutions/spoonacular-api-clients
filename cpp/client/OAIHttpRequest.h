/**
 * spoonacular API
 * The spoonacular Nutrition, Recipe, and Food API allows you to access over 380,000 recipes, thousands of ingredients, 80,000 food products, and 100,000 menu items. Our food ontology and semantic recipe search engine makes it possible to search for recipes using natural language queries, such as \"gluten free brownies without sugar\" or \"low fat vegan cupcakes.\" You can automatically calculate the nutritional information for any recipe, analyze recipe costs, visualize ingredient lists, find recipes for what's in your fridge, find recipes based on special diets, nutritional requirements, or favorite ingredients, classify recipes into types and cuisines, convert ingredient amounts, or even compute an entire meal plan. With our powerful API, you can create many kinds of food and especially nutrition apps.  Special diets/dietary requirements currently available include: vegan, vegetarian, pescetarian, gluten free, grain free, dairy free, high protein, whole 30, low sodium, low carb, Paleo, ketogenic, FODMAP, and Primal.
 *
 * The version of the OpenAPI document: 1.0
 * Contact: david@spoonacular.com
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

/**
 * Based on http://www.creativepulse.gr/en/blog/2014/restful-api-requests-using-qt-cpp-for-linux-mac-osx-ms-windows
 * By Alex Stylianos
 *
 **/

#ifndef OAI_HTTPREQUESTWORKER_H
#define OAI_HTTPREQUESTWORKER_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkReply>



namespace OpenAPI {

enum OAIHttpRequestVarLayout {NOT_SET, ADDRESS, URL_ENCODED, MULTIPART};

class OAIHttpRequestInputFileElement {

public:
    QString variable_name;
    QString local_filename;
    QString request_filename;
    QString mime_type;

};


class OAIHttpRequestInput {

public:
    QString url_str;
    QString http_method;
    OAIHttpRequestVarLayout var_layout;
    QMap<QString, QString> vars;
    QMap<QString, QString> headers;
    QList<OAIHttpRequestInputFileElement> files;
    QByteArray request_body;

    OAIHttpRequestInput();
    OAIHttpRequestInput(QString v_url_str, QString v_http_method);
    void initialize();
    void add_var(QString key, QString value);
    void add_file(QString variable_name, QString local_filename, QString request_filename, QString mime_type);

};


class OAIHttpRequestWorker : public QObject {
    Q_OBJECT

public:
    QByteArray response;
    QNetworkReply::NetworkError error_type;
    QString error_str;

    explicit OAIHttpRequestWorker(QObject *parent = nullptr);
    virtual ~OAIHttpRequestWorker();

    QMap<QByteArray, QByteArray> getResponseHeaders() const;
    QString http_attribute_encode(QString attribute_name, QString input);
    void execute(OAIHttpRequestInput *input);
    static QSslConfiguration* sslDefaultConfiguration;

signals:
    void on_execution_finished(OAIHttpRequestWorker *worker);

private:
    QNetworkAccessManager *manager;
    QMap<QByteArray, QByteArray> headers;
private slots:
    void on_manager_finished(QNetworkReply *reply);

};

}

#endif // OAI_HTTPREQUESTWORKER_H