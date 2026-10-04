
void __thiscall FUN_004ac469(int param_1,int *param_2,undefined3 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined3 *puVar4;
  int iVar5;
  undefined4 local_2c;
  undefined1 *local_c;
  undefined1 local_8;
  byte local_7;
  
  puVar4 = param_3;
  local_c = (undefined1 *)&local_2c;
  local_2c = (undefined3 *)CONCAT13((char)((uint)param_1 >> 0x18),*param_3);
  FUN_004796d9(&local_8);
  local_2c = puVar4;
  FUN_004b3e97(&local_c,&param_3);
  iVar5 = (uint)local_7 << ((char)DAT_006f0088 + 1U & 0x1f);
  iVar1 = *(int *)(param_1 + 0x5c);
  iVar2 = *(int *)(param_1 + 0x60);
  iVar3 = *(int *)(param_1 + (0x4c - DAT_006f0088) * 4);
  *param_2 = (int)(local_c + (-1 - iVar1));
  param_2[1] = (int)param_3 + (-iVar3 - iVar5);
  param_2[2] = (int)(local_c + iVar1 + -1);
  param_2[3] = (int)param_3 + (iVar2 - iVar5);
  return;
}

