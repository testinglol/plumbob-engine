
undefined4 * FUN_004dff75(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  SIZE_T dwSize;
  
  cVar1 = FUN_004e0015();
  if (cVar1 == '\0') {
    puVar2 = (undefined4 *)0xffffffff;
  }
  else {
    dwSize = 0x2000;
    while (puVar2 = VirtualAlloc((LPVOID)0x0,dwSize,0x1000,4), puVar2 != (undefined4 *)0x0) {
      iVar3 = (*DAT_006f2220)(param_1,puVar2 + 3,dwSize - 0x10);
      if (iVar3 == 0) {
        VirtualFree(puVar2,0,0x8000);
        break;
      }
      if ((uint)puVar2[3] <= dwSize >> 2) {
        puVar2[2] = 0;
        *puVar2 = 0x50594f52;
        puVar2[1] = dwSize;
        return puVar2;
      }
      if (0x1ffff < dwSize) break;
      VirtualFree(puVar2,0,0x8000);
      dwSize = dwSize + 0x2000;
    }
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}

