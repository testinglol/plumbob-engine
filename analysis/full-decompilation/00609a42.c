
void __thiscall FUN_00609a42(int *param_1,undefined4 *param_2,byte *param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint local_c;
  byte *local_8;
  
  local_8 = param_3;
  param_3 = (byte *)0x0;
  uVar1 = (**(code **)(*param_1 + 0x58))();
  uVar3 = param_4;
  if (param_4 != 0) {
    do {
      uVar2 = FUN_00609af3(local_8);
      if ((uVar2 == 0) || (param_4 < uVar2)) break;
      local_c = 0;
      for (uVar3 = uVar2; uVar3 != 0; uVar3 = uVar3 - 1) {
        local_c = local_c << 8 | (uint)*local_8;
        local_8 = local_8 + 1;
      }
      iVar5 = param_1[7];
      iVar4 = FUN_00608a15(local_c);
      uVar3 = iVar4 + (*(uint *)(iVar5 + 4) & 1);
      param_3 = (byte *)((int)param_3 + uVar3);
      param_4 = param_4 - uVar2;
    } while (param_4 != 0);
    if (param_3 != (byte *)0x0) {
      iVar5 = FUN_00608a15(local_c);
      param_3 = (byte *)((int)param_3 + (iVar5 - uVar3));
    }
  }
  param_2[2] = param_3;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[3] = uVar1;
  return;
}

