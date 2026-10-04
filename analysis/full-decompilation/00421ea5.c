
void __thiscall
FUN_00421ea5(int param_1,int *param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 400) == 0) {
    if (((param_2[1] == *(int *)(param_1 + 0x1b8)) && (*param_2 == *(int *)(param_1 + 0x1b4))) &&
       (*(int *)(param_1 + 0x1bc) == param_3)) {
      *(undefined2 *)(param_1 + 0x1c6) = (undefined2)param_5;
    }
    else {
      *(undefined2 *)(param_1 + 0x1c4) = 0;
      *(undefined2 *)(param_1 + 0x1c6) = 0;
    }
    *(undefined2 *)(param_1 + 0x1b0) = 0;
    if (*(int *)(param_1 + 0x1ac) == 0) {
      *(undefined2 *)(param_1 + 0x1b0) = 1;
    }
    cVar1 = FUN_00422083(param_2,param_3);
    if (cVar1 != '\0') {
      iVar3 = FUN_0046d9e5();
      iVar4 = FUN_00421e75();
      if (((iVar3 < iVar4) && (iVar4 != 0)) && (*(short *)(param_1 + 0x1b2) != 0)) {
        DAT_006e4a7c = 0x15;
      }
      else {
        *(undefined2 *)(param_1 + 0x1b0) = 1;
      }
      uVar5 = FUN_00407498((int)*(short *)(param_1 + 0x1c4));
      (**(code **)(**(int **)(param_1 + 0x1ac) + 0x58))
                (param_2,param_3,uVar5,(int)*(short *)(param_1 + 0x1c6),param_6);
      (**(code **)(**(int **)(param_1 + 0x1ac) + 0x74))();
    }
    FUN_00422c62(param_2,param_3,0,0,param_6);
    for (iVar3 = param_1; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x18c)) {
      *(undefined4 *)(iVar3 + 0x1b4) = *(undefined4 *)(iVar3 + 0xf4);
      *(undefined4 *)(iVar3 + 0x1b8) = *(undefined4 *)(iVar3 + 0xf8);
      *(undefined4 *)(iVar3 + 0x1bc) = *(undefined4 *)(iVar3 + 0x110);
      *(undefined2 *)(iVar3 + 0x1b0) = *(undefined2 *)(param_1 + 0x1b0);
      *(undefined4 *)(iVar3 + 0x1c0) = 0xbf800000;
    }
  }
  else {
    local_c = *param_2;
    local_8 = param_2[1];
    piVar2 = (int *)FUN_00422055(*(undefined4 *)(param_1 + 0x1a0),*(undefined4 *)(param_1 + 0x1a4));
    local_8 = local_8 - piVar2[1];
    local_c = local_c - *piVar2;
    (**(code **)(**(int **)(param_1 + 400) + 0x58))
              (&local_c,param_3 - *(int *)(param_1 + 0x1a8),param_4,param_5,param_6);
  }
  FUN_00422447();
  return;
}

