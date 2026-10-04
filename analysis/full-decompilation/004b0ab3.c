
void __thiscall FUN_004b0ab3(int param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  undefined4 local_2c;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  pcVar3 = param_2;
  cVar1 = *param_2;
  if ((((*(int *)(DAT_006e54d8 + 0x70) <= (int)cVar1) &&
       ((int)cVar1 <= *(int *)(DAT_006e54d8 + 0x74))) &&
      (*(int *)(DAT_006e54d8 + 0x78) <= (int)param_2[1])) &&
     ((int)param_2[1] <= *(int *)(DAT_006e54d8 + 0x7c))) {
    local_2c._3_1_ = (undefined1)((uint)param_1 >> 0x18);
    local_2c._0_3_ = CONCAT12(param_2[2],CONCAT11(param_2[1],cVar1));
    param_2 = (char *)&local_2c;
    iVar4 = FUN_004796d9(&local_c);
    bVar2 = *(byte *)(iVar4 + 1);
    local_2c = (int *)pcVar3;
    FUN_004b3e97(&local_8,&param_2);
    param_2 = (char *)((int)param_2 - ((uint)bVar2 << ((char)DAT_006f0088 + 1U & 0x1f)));
    local_1c = local_8 - *(int *)(param_1 + 0x5c);
    local_14 = *(int *)(param_1 + 0x5c) + local_8;
    local_10 = *(int *)(param_1 + 0x60) + (int)param_2;
    local_c = DAT_006fe838;
    DAT_006fe838 = DAT_006d6180;
    local_2c = &local_1c;
    local_18 = (int)param_2;
    FUN_005cddcf();
    DAT_006fe838 = local_c;
  }
  return;
}

