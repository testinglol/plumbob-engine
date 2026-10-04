
undefined4 FUN_00511f67(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_0043acf5(0xb6c90029);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    iVar2 = FUN_004703f1(*piVar1,param_1);
    return CONCAT31((int3)((uint)-iVar2 >> 8),'\x01' - (iVar2 != 0));
  }
  return 0;
}

