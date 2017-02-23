#pragma once
#include <rho.h>
#include "ioApi.h"
#include "fileInfo.h"

#include <core/blockingQueue.h>

namespace rho
{
    typedef	std::function<void(const fileInfo&)> watchCallback;

    namespace watcherMessageStatus
    {
        enum watcherMessageStatus
        {
            success,
            error
        };
    }

    struct watcherMessage
    {
        watcherMessage(rho::watchCallback cb, fileInfo fileChanged) :
            callback(cb), 
            fileChanged(fileChanged),
            status(watcherMessageStatus::success),
            error("")
        {}

        watcherMessage(rho::watchCallback cb, string error) :
            callback(cb),
            fileChanged(fileInfo()),
            status(watcherMessageStatus::error),
            error(error)
        {}

        rho::watchCallback callback;
        fileInfo fileChanged;
        watcherMessageStatus::watcherMessageStatus status;
        string error;
    };

    class watcher
    {
    private:
        std::atomic<bool> _programRunning;
        string _path;
        rho::blockingQueue<watcherMessage>* _queue;
        rho::watchCallback _callback;
        std::thread _watcherThread;
#ifdef _WIN32
        HANDLE _hDir;
#endif
        void watchDir();
    public:
        watcher(const string& path, rho::blockingQueue<rho::watcherMessage>* queue, rho::watchCallback callback) :
            _programRunning(true), _path(path), _queue(queue), _callback(callback) 
            {
            }

        IO_API void startWatch();
        IO_API void endWatch();
    };
}