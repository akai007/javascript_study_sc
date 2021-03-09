/**
 * Encapsulation
 */

const makeSubmit = () => {
    let sendMsgIntervalTime = 60
    const passTime = () => sendMsgIntervalTime-- // private method
    const waitTime = () => sendMsgIntervalTime
    const login = () => {
        sendMsgIntervalTime = 60
        return 'login'
    }
    setInterval(() => passTime, 1000)

    return {
        login: login,
        waitTime: waitTime
    }
}