
undefined4 FUN_004fc152(LPCSTR param_1,undefined4 param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  undefined4 local_114 [65];
  DWORD local_10 [2];
  HKEY local_8;
  
  uVar2 = 0;
  local_10[1] = 0x104;
  LVar1 = RegOpenKeyExA((HKEY)0x80000002,s_Software_Maxis_The_Sims_006cc09c,0,0x20019,&local_8);
  if (LVar1 != 0) {
    return 0;
  }
  LVar1 = RegQueryValueExA(local_8,param_1,(LPDWORD)0x0,local_10,(LPBYTE)local_114,local_10 + 1);
  if (LVar1 == 0) {
    if (local_10[0] == 1) {
      FUN_005d4bbf(local_114);
    }
    else {
      if (local_10[0] != 4) goto LAB_004fc1d7;
      FUN_005d5156(param_2,&DAT_006c08e4,local_114[0]);
    }
    uVar2 = 1;
  }
LAB_004fc1d7:
  RegCloseKey(local_8);
  return uVar2;
}

