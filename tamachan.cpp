#include "absl/container/btree_map.h"
#include "absl/strings/str_join.h"
#include "google/protobuf/util/time_util.h"
#include "message.pb.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace {
using google::protobuf::util::TimeUtil;
using std::cout;
using std::endl;
} // namespace

int main() {
  std::vector<std::string> v = {"foo", "bar", "baz"};
  std::string s = absl::StrJoin(v, "-");

  absl::btree_map<int, std::string> map1;

  absl::btree_map<int, std::string> map2 = {
      {1, "huey"},
      {2, "dewey"},
      {3, "louie"},
  };

  auto now = TimeUtil::GetCurrentTime();

  std::cout << "Joined string: " << s << "\n";

  riemann::Hilbert hilbert;
  *hilbert.mutable_hypothesis() = TimeUtil::SecondsToTimestamp(time(NULL));
  TimeUtil::SecondsToDuration(234234);
  cout << hilbert.DebugString() << endl;

  cout << hilbert.higashi() << endl;
  cout << riemann::Abelian_Name(hilbert.nabelito()) << endl;
  cout << "=====" << endl;
  cout << hilbert.DebugString() << endl;
  return 0;
}
