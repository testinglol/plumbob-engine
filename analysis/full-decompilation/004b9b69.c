
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b9b69(int param_1,float param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  float10 fVar4;
  undefined4 *puVar5;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  short local_8;
  short local_6;
  
  uVar2 = __ftol();
  local_1c = __ftol();
  local_18 = uVar2;
  local_14 = local_1c;
  local_10 = uVar2;
  FUN_0047bd91(&local_10,&local_14,*(undefined4 *)(DAT_006e54d8 + 0x84),0x401);
  iVar1 = (int)param_2;
  (**(code **)**(undefined4 **)((int)param_2 + 0x18))
            (&local_8,local_14,local_10,*(undefined4 *)(param_1 + 0xc),
             *(undefined4 *)((int)param_2 + 0x20),0);
  FUN_00478f70(&local_1c);
  *(int *)(param_1 + 0x10) = (int)local_6;
  *(int *)(param_1 + 0x14) = (int)local_8;
  param_2 = (float)(1 << ((char)*(undefined4 *)(iVar1 + 0x20) + 1U & 0x1f));
  iVar3 = __ftol();
  *(int *)(param_1 + 0x14) = local_8 - iVar3;
  fVar4 = (float10)FUN_00454f69(param_1 + 8);
  uVar2 = *(undefined4 *)(param_1 + 0xc);
  puVar5 = &param_2;
  local_c = 1 << ((char)*(undefined4 *)(iVar1 + 0x20) + 1U & 0x1f);
  param_2 = (float)(fVar4 * (float10)_DAT_0066881c);
  iVar3 = __ftol(puVar5,uVar2);
  FUN_004c9e4d(iVar1,(iVar3 - (4 << ((byte)*(undefined4 *)(iVar1 + 0x20) & 0x1f))) +
                     *(int *)(param_1 + 0x14),puVar5,uVar2);
  return;
}

