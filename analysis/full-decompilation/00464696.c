
void __thiscall FUN_00464696(int param_1,uint *param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int local_c;
  int local_8;
  
  puVar4 = param_2;
  local_c = param_1;
  local_8 = param_1;
  if ((*(int *)(param_1 + 0xc) == 2) || (*(int *)(param_1 + 0xc) == 1)) {
    param_2 = (uint *)(uint)(*param_2 != 0);
    FUN_004647a1(1,&param_2);
    iVar5 = param_3;
    if (param_2 != (uint *)0x0) {
      param_3 = FUN_00464749(*puVar4);
      FUN_004647a1(2,&param_3);
      FUN_004647a1(*(undefined4 *)(iVar5 + param_3 * 8),puVar4);
    }
  }
  else {
    FUN_004647a1(1,&local_8);
    if (local_8 == 0) {
      *param_2 = 0;
    }
    else {
      FUN_004647a1(2,&local_c);
      puVar4 = param_2;
      puVar1 = (undefined4 *)(param_3 + local_c * 8);
      FUN_004647a1(*puVar1,param_2);
      uVar2 = puVar1[1];
      uVar3 = *puVar4;
      if ((uVar2 & uVar3) != 0) {
        *puVar4 = uVar3 | uVar2;
      }
    }
  }
  return;
}

