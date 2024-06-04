import fetch from 'node-fetch';

async function getCryptoString(coinID) {
  try {
    const apiUrl = `https://api.coingecko.com/api/v3/coins/${coinID}?tickers=true&market_data=false&community_data=false&developer_data=false&sparkline=false`;
    const response = await fetch(apiUrl);

    if (response.ok) {
      const data = await response.json();

      const symbol = data.symbol;
      const name = data.name;
      const marketRank = data.market_cap_rank;
      const usdPrice = data.tickers[0].last;
      const image = data.image.small;

      const bitcoinString = `Name: ${name}\nSymbol: ${symbol}\nMarket Rank: ${marketRank}\nCurrent Price: ${usdPrice}$\n${image}`;
      return bitcoinString;
    } else {
      console.error('Failed to retrieve data. Status:', response.status);
      return null;
    }
  } catch (error) {
    console.error('An error occurred:', error);
    return null;
  }
}

export { getCryptoString };