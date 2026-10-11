SELECT { 'reported': { 'conectado': eventType = 'connected', 'desde': timestamp } } AS state
FROM '$aws/events/presence/+/+'
