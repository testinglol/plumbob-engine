
bool __thiscall
FUN_004673b8(int param_1,int param_2,undefined2 *param_3,undefined2 *param_4,undefined4 *param_5,
            undefined4 *param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined2 local_14;
  undefined2 local_c;
  
  FUN_004692b6(&param_2,param_2);
  bVar4 = param_2 != *(int *)(param_1 + 0x10);
  if (bVar4) {
    uVar1 = *(undefined4 *)(param_2 + 0x18);
    uVar2 = *(undefined4 *)(param_2 + 0x1c);
    uVar3 = *(undefined4 *)(param_2 + 0x20);
    local_14 = (undefined2)*(undefined4 *)(param_2 + 0x14);
    *param_3 = local_14;
    *param_5 = uVar1;
    local_c = (undefined2)uVar2;
    *param_4 = local_c;
    *param_6 = uVar3;
  }
  else {
    *param_3 = 0;
    *param_4 = 0;
    *param_5 = 0;
    *param_6 = 0;
  }
  return bVar4;
}

