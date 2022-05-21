import glob
import os
print('削除開始')
for name in glob.glob('**/*.out',recursive=True):
    os.remove(name)

print('削除完了')