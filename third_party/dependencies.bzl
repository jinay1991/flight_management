load("@//third_party/googletest:googletest.bzl", "googletest")
load("@//third_party/nholthaus:nholthaus.bzl", "nholthaus")
load("@//third_party/nlohmann:nlohmann.bzl", "nlohmann")

def third_party_dependencies():
    """ Load 3rd party dependencies """
    googletest()
    nholthaus()
    nlohmann()
