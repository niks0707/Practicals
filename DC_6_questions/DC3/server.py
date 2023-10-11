import Pyro4

@Pyro4.expose
class StringOperations:
    def compare_strings(self, str1, str2):
        return str1 == str2

    def count_characters(self, string):
        return len(string)

if __name__ == "__main__":
    with Pyro4.Daemon() as daemon:
        uri = daemon.register(StringOperations)
        print("Server URI:", uri)
        daemon.requestLoop()
