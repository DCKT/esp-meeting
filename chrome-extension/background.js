const onTabCreation = async (tab) => {
  const tabs = await chrome.tabs.query({ url: "https://meet.google.com/*" });

  if (tabs.length) {
    await fetch("http://localhost:9887/on", { mode: "no-cors" });
  }
};
const onTabDeletion = async (tab) => {
  const tabs = await chrome.tabs.query({ url: "https://meet.google.com/*" });
  if (!tabs.length) {
    await fetch("http://localhost:9887/off", { mode: "no-cors" });
  }
};

chrome.tabs.onCreated.addListener(onTabCreation);
chrome.tabs.onRemoved.addListener(onTabDeletion);
