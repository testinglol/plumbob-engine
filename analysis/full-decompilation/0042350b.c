
void __fastcall FUN_0042350b(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined1 local_2c [4];
  int local_28;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  int local_10;
  int local_c;
  uint local_8;
  
  cVar1 = FUN_00432644();
  if (cVar1 != '\0') {
    local_8 = 0;
    iVar3 = 0;
    do {
      local_10 = param_1[0x3d];
      local_c = param_1[0x3e];
      piVar2 = (int *)FUN_004222bd(((short)param_1[0x13] + iVar3) % 8);
      local_c = local_c + piVar2[1];
      local_10 = local_10 + *piVar2;
      FUN_004235c6(local_2c,&local_10,param_1[0x44]);
      while (local_28 != 0) {
        cVar1 = (**(code **)(*param_1 + 0x5c))(local_28);
        if (cVar1 != '\0') {
          local_8 = local_8 | 1 << ((byte)iVar3 & 0x1f);
        }
        FUN_0043f3b9();
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    local_18 = (undefined2)local_8;
    local_16 = 0;
    local_14 = 0;
    local_12 = 0;
    FUN_00422d79(8,0,&local_18);
  }
  return;
}

