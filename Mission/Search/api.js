export const API_ENDPOINT = 'https://wr4a6p937i.execute-api.ap-northeast-2.amazonaws.com/dev'

const request = async (url) => {
    const res = await fetch(url)

    if(res.ok){
        const json = await res.json()
        return json
    }

    throw new Error('요청 실패')
}

export const fetchLanguages = async (keyword) => request(`${API_ENDPOINT}/languages?keyword=${keyword}`)

