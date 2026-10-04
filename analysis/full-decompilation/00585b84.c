
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00585b84(int *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  
  iVar1 = (**(code **)(*param_1 + 0xac))();
  if ((iVar1 != 0) &&
     ((cVar3 = '\x01', param_2 == '\0' || (cVar3 = *(char *)((int)param_1 + 0x109), cVar3 != '\0')))
     ) {
    iVar2 = (**(code **)(*param_1 + 0x34))();
    iVar1 = param_1[4];
    param_1[0x2d] = iVar2;
    if ((iVar1 != 0) && (ABS(*(float *)(iVar1 + 0x2c)) <= _DAT_0067343c)) {
      (**(code **)(*param_1 + 0xac))(iVar1);
      FUN_005a0903(iVar1);
      param_1[4] = 0;
    }
    FUN_004341a6(0);
    (**(code **)(*param_1 + 0xac))();
    FUN_005992ca(param_1[0x2d],cVar3,0);
    (**(code **)(*param_1 + 0x60))();
    FUN_005994da(0);
    uVar4 = 0;
    (**(code **)(*param_1 + 0xac))(0);
    FUN_005a1444(uVar4);
  }
  return;
}

