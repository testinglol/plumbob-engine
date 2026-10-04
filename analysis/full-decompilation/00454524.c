
void __thiscall FUN_00454524(int param_1,int param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined **local_26c;
  undefined **local_268;
  undefined4 local_264;
  undefined1 local_260 [4];
  undefined1 local_25c [256];
  undefined **local_15c;
  undefined4 local_158;
  undefined1 local_150 [64];
  undefined1 local_110 [256];
  int local_10;
  int *local_c;
  int local_8;
  
  iVar1 = param_2;
  local_10 = param_1 + 8;
  local_8 = FUN_004754ce();
  FUN_00635858(local_110,s_Object_id___d_name___s_Stack_siz_006c4294,(int)*(short *)(param_1 + 0xf0)
               ,*(undefined4 *)(*(int *)(param_1 + 0x11c) + 0x18),local_8);
  FUN_005bc69b(local_110);
  if (param_2 != 0) {
    FUN_006323d0(local_110);
  }
  sVar2 = FUN_0047471f();
  if (sVar2 != 0) {
    FUN_0046f824(local_25c,0,0x100);
    local_268 = &PTR_FUN_00666524;
    FUN_0043a0ca(&local_268);
    FUN_00635858(local_110,s_Error___s_006c4288,local_264);
    FUN_005bc69b(local_110);
    if (param_2 != 0) {
      FUN_006323d0(local_110);
    }
  }
  FUN_00635858(local_110,s_Iterations___d_006c4278,*(undefined4 *)(param_1 + 4));
  FUN_005bc69b(local_110);
  if (param_2 != 0) {
    FUN_006323d0(local_110);
  }
  while (local_8 = local_8 + -1, -1 < local_8) {
    iVar3 = FUN_004754ac(local_8);
    FUN_00635858(local_110,s_Frame__d__006c4268,local_8);
    FUN_005bc69b(local_110);
    if (iVar1 != 0) {
      FUN_006323d0(local_110);
    }
    FUN_00635858(local_110,s_Stack_Object_id___d_006c424c,(int)*(short *)(iVar3 + 4));
    FUN_005bc69b(local_110);
    if (iVar1 != 0) {
      FUN_006323d0(local_110);
    }
    FUN_0046f824(local_150,0,0x40);
    local_15c = &PTR_FUN_0066651c;
    FUN_004747c8(&local_15c);
    FUN_0046f824(local_260,0,0x104);
    param_2 = 0;
    local_26c = &PTR_FUN_006664e8;
    if (*(undefined4 **)(iVar3 + 0xc) != (undefined4 *)0x0) {
      local_c = (int *)**(undefined4 **)(iVar3 + 0xc);
      uVar4 = FUN_004754d8();
      local_c = (int *)(*(code *)*local_c)(uVar4);
      uVar4 = FUN_004754d8();
      iVar5 = FUN_0040204f(uVar4);
      if (iVar5 != 0) {
        param_2 = *(undefined4 *)(iVar5 + 8);
      }
      if (local_c != (int *)0x0) {
        (**(code **)(*local_c + 0x24))(&local_26c);
      }
    }
    FUN_00635858(local_110,s_Node___d_006c423c,(int)*(short *)(iVar3 + 2));
    FUN_005bc69b(local_110);
    if (iVar1 != 0) {
      FUN_006323d0(local_110);
    }
    sVar2 = FUN_004754d8(local_158,param_2);
    FUN_00635858(local_110,s_Tree__id__d_name___s__version__d_006c4214,(int)sVar2);
    FUN_005bc69b(local_110);
    if (iVar1 != 0) {
      FUN_006323d0(local_110);
    }
    FUN_00635858(local_110,s_from__s_006c4204,local_268);
    FUN_005bc69b(local_110);
    if (iVar1 != 0) {
      FUN_006323d0(local_110);
    }
    FUN_00635858(local_110,s_Prim_state___d_006c41f0,*(undefined4 *)(iVar3 + 8));
    FUN_005bc69b(local_110);
    if (iVar1 != 0) {
      FUN_006323d0(local_110);
    }
    FUN_00635858(local_110,s_Params__006c41e4);
    FUN_005bc69b(local_110);
    if (iVar1 != 0) {
      FUN_006323d0(local_110);
    }
    param_2 = 0;
    if (*(char *)(iVar3 + 7) != '\0') {
      do {
        iVar5 = FUN_004752f8();
        FUN_00635858(local_110,&PTR_DAT_006c41e0,(int)*(short *)(iVar5 + param_2 * 2));
        FUN_005bc69b(local_110);
        if (iVar1 != 0) {
          FUN_006323d0(local_110);
        }
        param_2 = param_2 + 1;
      } while (param_2 < (int)(uint)*(byte *)(iVar3 + 7));
    }
    FUN_00635858(local_110,s_Locals__006c41d4);
    FUN_005bc69b(local_110);
    if (iVar1 != 0) {
      FUN_006323d0(local_110);
    }
    param_2 = 0;
    if (*(char *)(iVar3 + 6) != '\0') {
      do {
        iVar5 = FUN_004752fc();
        FUN_00635858(local_110,&PTR_DAT_006c41e0,(int)*(short *)(iVar5 + param_2 * 2));
        FUN_005bc69b(local_110);
        if (iVar1 != 0) {
          FUN_006323d0(local_110);
        }
        param_2 = param_2 + 1;
      } while (param_2 < (int)(uint)*(byte *)(iVar3 + 6));
    }
    FUN_00635858(local_110,&DAT_006c08dc);
    FUN_005bc69b(local_110);
    if (iVar1 != 0) {
      FUN_006323d0(local_110);
    }
  }
  return;
}

