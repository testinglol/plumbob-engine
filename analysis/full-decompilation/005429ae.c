
void __thiscall FUN_005429ae(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_3c [16];
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
  
  if (((-1 < param_4) && (param_4 < 6)) &&
     (iVar1 = *(int *)(param_1 + 100 + param_4 * 4), iVar1 != 0)) {
    local_c = param_2;
    local_8 = param_3;
    local_2c = *(undefined4 *)(iVar1 + 0x14);
    local_28 = *(undefined4 *)(iVar1 + 0x18);
    local_24 = *(undefined4 *)(iVar1 + 0x1c);
    local_20 = *(undefined4 *)(iVar1 + 0x20);
    puVar2 = (undefined4 *)FUN_004df599(local_3c,param_1 + 0x394);
    local_1c = *puVar2;
    local_18 = puVar2[1];
    local_14 = puVar2[2];
    local_10 = puVar2[3];
    FUN_004ba5ac(&local_c);
    (**(code **)(**(int **)(param_1 + 0x390) + 0x9c))(iVar1,&local_2c,&local_1c,0);
  }
  return;
}

