
void __fastcall FUN_005da719(int param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  DWORD DVar4;
  undefined4 *puVar5;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_c;
  int local_8;
  
  if (*(char *)(param_1 + 0x1e1) != '\0') {
    FUN_005d9928(&local_c,&local_8);
    FUN_005dac30(0xd,0,local_8 << 0x10 | local_c);
    *(undefined1 *)(param_1 + 0x1e1) = 0;
  }
  *(undefined1 *)(param_1 + 0x1e0) = 1;
  if ((*(int *)(param_1 + 0x1d8) < 0) &&
     (*(int *)(param_1 + 0x1d0) - *(int *)(param_1 + 0x1cc) >> 4 != 0)) {
    *(undefined4 *)(param_1 + 0x1d8) = 0;
    *(int *)(param_1 + 0x1dc) = *(int *)(param_1 + 0x1d0) - *(int *)(param_1 + 0x1cc) >> 4;
    if (1 < (uint)(*(int *)(param_1 + 0x1d0) - *(int *)(param_1 + 0x1cc) >> 4)) {
      FUN_005db82f(*(undefined4 *)(param_1 + 0x1cc),*(undefined4 *)(param_1 + 0x1d0));
    }
  }
  DVar4 = timeGetTime();
  iVar2 = *(int *)(param_1 + 0x1d8);
  while( true ) {
    if ((iVar2 < 0) || (*(int *)(param_1 + 0x1dc) <= *(int *)(param_1 + 0x1d8))) goto LAB_005da82e;
    puVar5 = (undefined4 *)(*(int *)(param_1 + 0x1d8) * 0x10 + *(int *)(param_1 + 0x1cc));
    if ((int)DVar4 < (int)puVar5[2]) break;
    puVar5[2] = puVar5[1] + puVar5[2];
    cVar3 = FUN_005da398(*puVar5);
    if (cVar3 != '\0') {
      local_18 = puVar5[3];
      local_1c = 0x1a;
      (*(code *)**(undefined4 **)*puVar5)(&local_1c);
    }
    piVar1 = (int *)(param_1 + 0x1d8);
    *piVar1 = *piVar1 + 1;
    iVar2 = *piVar1;
  }
  *(undefined4 *)(param_1 + 0x1d8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1dc) = 0xffffffff;
LAB_005da82e:
  if (*(int *)(param_1 + 0x1dc) <= *(int *)(param_1 + 0x1d8)) {
    *(undefined4 *)(param_1 + 0x1d8) = 0xffffffff;
    *(int *)(param_1 + 0x1dc) = -1;
  }
  *(undefined1 *)(param_1 + 0x1e0) = 0;
  return;
}

