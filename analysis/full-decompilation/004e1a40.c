
void FUN_004e1a40(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 local_8;
  
  puVar3 = (undefined4 *)FUN_00425e2d();
  for (piVar4 = (int *)*puVar3; piVar4 != (int *)puVar3[1]; piVar4 = piVar4 + 1) {
    iVar1 = *piVar4;
    if ((((((*(int *)(iVar1 + 0x110) == 0) && (iVar2 = *(int *)(iVar1 + 0x10c), iVar2 != 0)) &&
          (iVar2 != 2000)) && ((iVar2 != 4000 && (iVar2 != 5000)))) &&
        ((iVar2 != 0x157c && (iVar2 != 6000)))) && ((iVar2 < 3000 || (0xbc1 < iVar2)))) {
      local_8 = *(undefined4 *)(iVar1 + 0x10c);
      FUN_0042eab4(&local_8);
    }
  }
  return;
}

