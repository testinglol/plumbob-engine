
undefined1 __fastcall FUN_005e3bfd(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  DWORD DVar5;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  if (*(char *)((int)param_1 + 0x16d) != '\0') {
    if (param_1[0x35] == 0) {
      iVar3 = (**(code **)(*param_1 + 0xc4))();
      param_1[0x35] = iVar3;
      if (iVar3 == 0) goto LAB_005e3ce2;
    }
    cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar2 != '\0') {
      iVar3 = param_1[0x35];
      local_2c = *(undefined4 *)(iVar3 + 0x14);
      local_28 = *(undefined4 *)(iVar3 + 0x18);
      local_24 = *(undefined4 *)(iVar3 + 0x1c);
      local_20 = *(undefined4 *)(iVar3 + 0x20);
      local_1c = local_2c;
      local_18 = local_28;
      local_14 = local_24;
      local_10 = local_20;
      FUN_004ba5ac(param_1 + 7);
      (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x35],&local_2c,&local_1c,0);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
    puVar1 = (undefined4 *)param_1[0x35];
    if ((puVar1[7] != param_1[0x21] - param_1[0x1f]) || (puVar1[8] != param_1[0x22] - param_1[0x20])
       ) {
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      param_1[0x35] = 0;
      piVar4 = (int *)(**(code **)(*param_1 + 0x18))();
      (**(code **)(*piVar4 + 0x168))();
    }
  }
LAB_005e3ce2:
  (**(code **)(*param_1 + 0x1b0))();
  (**(code **)(*param_1 + 0x1b4))();
  if ((((-1 < param_1[0x39]) && (-1 < param_1[0x3a])) && (param_1[0x39] < param_1[0x3b])) &&
     ((param_1[0x3a] < param_1[0x3c] && (cVar2 = (**(code **)(*param_1 + 0x1a4))(), cVar2 == '\0')))
     ) {
    return 0;
  }
  if (param_1[0x14] != param_1[0x13]) {
    (**(code **)(*param_1 + 0x1ac))();
  }
  (**(code **)(*param_1 + 0x1a8))();
  if ((char)param_1[0x5b] != '\0') {
    FUN_005d9928(local_c,local_8);
    DVar5 = timeGetTime();
    if ((uint)param_1[0x56] < DVar5 - param_1[0x57]) {
      FUN_005e4b04(0x13);
      *(undefined1 *)(param_1 + 0x5b) = 0;
    }
    else {
      (**(code **)(*param_1 + 0x168))();
    }
  }
  return 1;
}

