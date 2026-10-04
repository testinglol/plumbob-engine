
void __thiscall FUN_004796d9(int param_1,int *param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  local_8 = param_1;
  FUN_00434ffd(-*(int *)(param_1 + 0x84) & 3);
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + 0xc) + (char)param_3 * 4);
  pbVar3 = &DAT_006c4eac + *(int *)(param_1 + 0x84) * 4;
  iVar4 = 0;
  do {
    bVar1 = *pbVar3;
    iVar5 = iVar4 + 1;
    pbVar3 = pbVar3 + 1;
    *(undefined1 *)((int)&local_8 + iVar4) =
         *(undefined1 *)((uint)bVar1 + iVar2 + param_3._1_1_ * 4);
    iVar4 = iVar5;
  } while (iVar5 < 4);
  *param_2 = local_8;
  return;
}

