
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_00405333(undefined4 param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = FUN_004ea800(param_1);
  fVar1 = (float)iVar2 * _DAT_00666578;
  iVar2 = FUN_004051e0(param_1);
  return (float)iVar2 <= fVar1;
}

