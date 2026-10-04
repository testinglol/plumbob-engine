
void __fastcall FUN_00521022(int *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int **ppiVar5;
  undefined4 uVar6;
  int iVar7;
  int *local_c;
  int *local_8;
  
  local_c = param_1;
  local_8 = param_1;
  cVar3 = (**(code **)(*param_1 + 200))();
  if (cVar3 == '\0') {
    FUN_005a5631(0x1324,param_1 + 0x79,4);
    FUN_005a5631(0x1327,param_1 + 0x78,4);
    (**(code **)(*param_1 + 0x19c))(0,4,1);
    FUN_005e4071(DAT_006f2a94);
    piVar1 = *(int **)(param_1[0x78] + 0x20);
    local_8 = piVar1;
    piVar4 = (int *)FUN_005e40a5();
    local_c = (int *)(**(code **)(*piVar4 + 0x58))();
    ppiVar5 = &local_8;
    if ((int)piVar1 <= (int)local_c) {
      ppiVar5 = &local_c;
    }
    FUN_004ec1a7(*ppiVar5);
    iVar7 = param_1[0x14];
    iVar2 = param_1[0x13];
    local_c = (int *)FUN_005e40a5();
    local_8 = (int *)*local_c;
    uVar6 = FUN_004096c2(iVar7 - iVar2);
    iVar7 = (*(code *)local_8[0x1a])(uVar6);
    FUN_004ec186(*(int *)(param_1[0x78] + 0x1c) + 9 + iVar7);
    param_1[0x3e] = 2;
    param_1[0x3d] = 1;
    thunk_FUN_005dbf32();
  }
  else {
    thunk_FUN_005dbf32();
  }
  return;
}

