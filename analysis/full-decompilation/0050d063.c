
undefined4 __fastcall FUN_0050d063(int param_1)

{
  char cVar1;
  int iVar2;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*(int *)(param_1 + 0x84) != *(int *)(param_1 + 0x7c)) &&
     (*(int *)(param_1 + 0x88) != *(int *)(param_1 + 0x80))) {
    if (DAT_006e5490 < *(uint *)(param_1 + 0xf0)) {
      FUN_00473496(DAT_006e5490);
      iVar2 = __ftol();
      local_8 = (*(int *)(param_1 + 0x88) - iVar2) - *(int *)(param_1 + 0x80);
    }
    else {
      local_8 = 0;
    }
    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar1 != '\0') {
      iVar2 = *(int *)(param_1 + 0x108);
      local_18 = *(int *)(iVar2 + 0x14);
      local_14 = *(int *)(iVar2 + 0x18);
      local_10 = *(int *)(iVar2 + 0x1c);
      local_28 = local_18 + *(int *)(param_1 + 0x1c);
      local_20 = local_10 + *(int *)(param_1 + 0x1c);
      local_1c = *(int *)(param_1 + 0x20) + *(int *)(iVar2 + 0x20);
      local_c = *(int *)(iVar2 + 0x20) - local_8;
      local_24 = local_14 + *(int *)(param_1 + 0x20) + local_8;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))(iVar2,&local_18,&local_28,0);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  return 1;
}

