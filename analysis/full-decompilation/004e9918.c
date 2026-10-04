
undefined4 FUN_004e9918(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if ((((*(int *)(*DAT_006e486c + 0x10) != 0) && (-1 < param_1)) &&
      (iVar1 = FUN_004102e1(), param_1 < iVar1)) &&
     (puVar2 = (undefined4 *)FUN_004102ab(param_1), puVar2 != (undefined4 *)0x0)) {
    uVar3 = FUN_004e988f(*puVar2);
    return uVar3;
  }
  return 0xffffffff;
}

