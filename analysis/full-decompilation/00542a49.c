
void __thiscall
FUN_00542a49(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_44 [16];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((param_4 < 0) || (2 < param_4)) {
    param_4 = 0;
  }
  if ((param_5 < -0xff) || (0 < param_5)) {
    param_5 = 0;
  }
  iVar1 = *(int *)(param_1 + 0x80 + param_4 * 4);
  if (iVar1 != 0) {
    local_14 = 0;
    local_10 = 0;
    local_c = param_2;
    local_8 = param_3;
    local_34 = *(undefined4 *)(iVar1 + 0x14);
    local_30 = *(undefined4 *)(iVar1 + 0x18);
    local_2c = *(undefined4 *)(iVar1 + 0x1c);
    local_28 = *(undefined4 *)(iVar1 + 0x20);
    puVar2 = (undefined4 *)FUN_004df599(local_44,param_1 + 0x394);
    local_24 = *puVar2;
    local_20 = puVar2[1];
    local_1c = puVar2[2];
    local_18 = puVar2[3];
    FUN_004ba5ac(&local_c);
    FUN_004ba37c(*(undefined4 *)(param_1 + 0x390),&local_24,iVar1,*(undefined4 *)(iVar1 + 0x60),
                 &local_14,param_5);
  }
  return;
}

