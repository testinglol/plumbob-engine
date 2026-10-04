
int __thiscall FUN_0041950d(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 local_48 [2];
  undefined1 local_3f;
  undefined1 local_3d;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined4 local_8;
  
  iVar2 = *(int *)(param_1 + 0x20);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    iVar1 = FUN_0041a346(iVar2);
    *(int *)(param_1 + 0x20) = iVar2;
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  pcVar3 = s_IFF_FILE_____TYPE_FOLLOWED_BY_SI_006c2084;
  puVar4 = local_48;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    puVar4 = puVar4 + 1;
  }
  local_c = (undefined1)((uint)param_3 >> 0x18);
  local_b = (undefined1)((uint)param_3 >> 0x10);
  local_a = (undefined1)((uint)param_3 >> 8);
  local_3f = 0x32;
  local_3d = 0x35;
  local_9 = (undefined1)param_3;
  local_8 = 0x40;
  iVar2 = FUN_004131a0(0);
  if ((iVar2 == 0) && (iVar2 = FUN_00412f9f(local_48,&local_8), iVar2 == 0)) {
    FUN_004131cb();
    *(undefined4 *)(param_1 + 0x20) = param_3;
    if (param_2 == (-(uint)(param_1 != 0) & param_1 + 0xcU)) {
      *(undefined1 *)(param_1 + 0x24) = 1;
    }
    iVar2 = 0;
  }
  return iVar2;
}

