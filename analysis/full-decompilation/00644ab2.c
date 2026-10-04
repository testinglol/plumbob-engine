
void FUN_00644ab2(DWORD param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  int iVar5;
  char acStackY_1e3 [7];
  undefined1 *puStackY_1dc;
  char *pcStackY_1d8;
  undefined4 uStackY_1d4;
  undefined1 *puStackY_1d0;
  undefined4 uStackY_1cc;
  undefined1 *puStackY_1c8;
  undefined *puStackY_1c4;
  LPCVOID lpBuffer;
  LPDWORD lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  CHAR local_1a8 [260];
  undefined1 local_a4 [160];
  
  iVar5 = 0;
  pDVar2 = &DAT_006ddd20;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x6dddb0);
  if (param_1 == (&DAT_006ddd20)[iVar5 * 2]) {
    if ((DAT_00703afc == 1) || ((DAT_00703afc == 0 && (DAT_006daae4 == 1)))) {
      lpNumberOfBytesWritten = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x6ddd24);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      puStackY_1c4 = (undefined *)0x644bfb;
      hFile = GetStdHandle(0xfffffff4);
      puStackY_1c4 = (undefined *)0x644c02;
      WriteFile(hFile,lpBuffer,sVar4,lpNumberOfBytesWritten,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_006358b0();
      }
      sVar4 = _strlen(local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen(local_1a8);
        puStackY_1c4 = (undefined *)0x644b7c;
        _strncpy(acStackY_1e3 + sVar4,&DAT_006c220c,3);
      }
      FUN_006358b0();
      puStackY_1c4 = (undefined *)0x644b9d;
      FUN_006358c0();
      puStackY_1c8 = local_a4;
      puStackY_1c4 = &DAT_006c2b5c;
      uStackY_1cc = 0x644bae;
      FUN_006358c0();
      uStackY_1cc = *(undefined4 *)(iVar5 * 8 + 0x6ddd24);
      puStackY_1d0 = local_a4;
      uStackY_1d4 = 0x644bc0;
      FUN_006358c0();
      uStackY_1d4 = 0x12010;
      puStackY_1dc = local_a4;
      pcStackY_1d8 = "Microsoft Visual C++ Runtime Library";
      acStackY_1e3[3] = -0x2a;
      acStackY_1e3[4] = 'K';
      acStackY_1e3[5] = 'd';
      acStackY_1e3[6] = '\0';
      FUN_0064844a();
    }
  }
  return;
}

